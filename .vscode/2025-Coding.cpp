#include <cstdint>
#include <iostream>

class M3508_Motor {
  private:
    float ratio_; // 电机减速比

    float angle_;       // deg 输出端累计转动角度
    float delta_angle_; // deg 输出端新转动的角度

    float ecd_angle_;       // deg 当前电机编码器角度
    float last_ecd_angle_;  // deg 上次电机编码器角度
    float delta_ecd_angle_; // deg 编码器端新转动的角度

    float rotate_speed_; // dps 反馈转子转速
    float current_;      // A   反馈转矩电流
    float temp_;         // °C  反馈电机温度

    float error_estimate; // 反应估算误差累积
    float error;          // 反应上一次计算留下的误差
    int cnt;
    bool flag; // 判断是否已经申报误差超过10°的flag

  public:
    M3508_Motor();
    float get_angle() {};         // 假设该函数用来读取当前编码器角度
    float get_mem_ecd_angle() {}; // 假设该函数用来读取上次编码器角度
    float get_rotate_speed() {};  // 假设该函数用来读取转子转速
    float get_current() {};       // 假设该函数用来读取转矩电流
    float get_temp() {};          // 假设该函数用来读取电机温度
    float linearMapping(int in, int in_min, int in_max, float out_min, float out_max);
    void canRxMsgCallback_v1(uint8_t rx_data[8]);
    void canRxMsgCallback_v2(uint8_t rx_data[8]);
    void canRxMsgCallback_v3(uint8_t rx_data[8]);
    float ErrorEstimate(uint8_t rx_data[8]);
    void canRxMsgCallback_v4(uint8_t rx_data[8]);
};

// M3508_Motor::M3508_Motor() {
//     this->ratio_ = 3592 / 187;
//     this->error_estimate=this->error=0.0;
//     this->flag=false;
//     this->cnt=0;
//     this->ecd_angle_ = get_angle();
//     this->last_ecd_angle_ = get_mem_ecd_angle();
//     this->delta_ecd_angle_ = ecd_angle_ - last_ecd_angle_; //  相减得到和上一次之间的角度差
//     this->angle_ = this->delta_angle_ = delta_ecd_angle_ / ratio_; //  输出端累计转过角度和新转动的角度都重新计算，不考虑之前的累积
//     this->rotate_speed_ = get_rotate_speed();
//     this->current_ = get_current();
//     this->temp_ = get_temp();
// }

M3508_Motor::M3508_Motor() {
    this->ratio_ = 3592 / 187;
    this->error = 0.0;
    this->last_ecd_angle_ = this->ecd_angle_ = 0;
    // canRxMsgCallback_v1(rx_data[8]);
}

float M3508_Motor::linearMapping(int in, int in_min, int in_max, float out_min, float out_max) {
    float k = (out_max - out_min) / (in_max - in_min); // 计算斜率
    return out_min + k * (in - in_min);
}

void M3508_Motor::canRxMsgCallback_v1(uint8_t rx_data[8]) {
    uint16_t ecd = (uint16_t)rx_data[0] << 8 | (uint16_t)rx_data[1];
    this->last_ecd_angle_ = this->ecd_angle_;
    this->ecd_angle_ = linearMapping(ecd, 0, 8191, 0, 365);
    this->rotate_speed_ = (uint16_t)rx_data[2] << 8 | (uint16_t)rx_data[3];
    this->current_ = (uint16_t)rx_data[4] << 8 | (uint16_t)rx_data[5];
    this->temp_ = rx_data[6];
}

void M3508_Motor::canRxMsgCallback_v2(uint8_t rx_data[8]) {
    uint16_t ecd = (uint16_t)rx_data[0] << 8 | (uint16_t)rx_data[1];
    this->last_ecd_angle_ = this->ecd_angle_;
    this->ecd_angle_ = linearMapping(ecd, 0, 8191, 0, 365);
    this->rotate_speed_ = (uint16_t)rx_data[2] << 8 | (uint16_t)rx_data[3];
    this->current_ = (uint16_t)rx_data[4] << 8 | (uint16_t)rx_data[5];
    this->temp_ = rx_data[6];
    this->delta_ecd_angle_ = ecd_angle_ - last_ecd_angle_;
    if (this->delta_ecd_angle_ < 0) {
        this->delta_ecd_angle_ += 360;
    }
}

void M3508_Motor::canRxMsgCallback_v3(uint8_t rx_data[8]) {
    uint16_t ecd = (uint16_t)rx_data[0] << 8 | (uint16_t)rx_data[1];
    this->last_ecd_angle_ = this->ecd_angle_;
    this->ecd_angle_ = linearMapping(ecd, 0, 8191, 0, 360);
    this->rotate_speed_ = (uint16_t)rx_data[2] << 8 | (uint16_t)rx_data[3];
    this->current_ = (uint16_t)rx_data[4] << 8 | (uint16_t)rx_data[5];
    this->temp_ = rx_data[6];
    this->delta_ecd_angle_ = ecd_angle_ - last_ecd_angle_;
    if (fabs(this->delta_ecd_angle_) > 180) {
        if (delta_ecd_angle_ < 0) {
            delta_ecd_angle_ += 360;
        } else {
            delta_ecd_angle_ -= 360;
        }
    }
    this->delta_angle_ = delta_ecd_angle_ / ratio_;
    this->angle_ += delta_angle_;
}

float M3508_Motor::ErrorEstimate(uint8_t rx_data[8]) {
    this->cnt++;
    uint16_t ecd = (uint16_t)rx_data[0] << 8 | (uint16_t)rx_data[1];
    this->last_ecd_angle_ = this->ecd_angle_;
    this->ecd_angle_ = linearMapping(ecd, 0, 8191, 0, 360);
    this->delta_ecd_angle_ = ecd_angle_ - last_ecd_angle_;
    if (fabs(this->delta_ecd_angle_) > 180) {
        if (delta_ecd_angle_ < 0) {
            delta_ecd_angle_ += 360;
        } else {
            delta_ecd_angle_ -= 360;
        }
    }
    this->delta_angle_ = delta_ecd_angle_ / ratio_;
    float c; // 获取本次计算造成的误差
    float t;
    t = angle_ + delta_angle_;
    c = (t - angle_) - delta_angle_;
    this->error_estimate += c;
    this->angle_ = t;
    if (error_estimate < 10) {
        return -1;
    } else {
        if (flag == true) {
            return -1;
        } else {
            return cnt / 1000;
            flag = true;
        }
    }
}

void M3508_Motor::canRxMsgCallback_v4(uint8_t rx_data[8]) {
    uint16_t ecd = (uint16_t)rx_data[0] << 8 | (uint16_t)rx_data[1];
    this->last_ecd_angle_ = this->ecd_angle_;
    this->ecd_angle_ = linearMapping(ecd, 0, 8191, 0, 360);
    this->rotate_speed_ = (uint16_t)rx_data[2] << 8 | (uint16_t)rx_data[3];
    this->current_ = (uint16_t)rx_data[4] << 8 | (uint16_t)rx_data[5];
    this->temp_ = rx_data[6];
    this->delta_ecd_angle_ = ecd_angle_ - last_ecd_angle_;
    if (fabs(this->delta_ecd_angle_) > 180) {
        if (delta_ecd_angle_ < 0) {
            delta_ecd_angle_ += 360;
        } else {
            delta_ecd_angle_ -= 360;
        }
    }
    this->delta_angle_ = delta_ecd_angle_ / ratio_;
    float c; // 获取本次计算造成的误差
    float t;
    float y = delta_angle_ - error;
    t = angle_ + y;
    c = (t - angle_) - y;
    this->error = c;
    this->angle_ = t;
}