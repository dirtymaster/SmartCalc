#include "controller.h"

namespace s21 {
Controller::Controller() { model_ = new Model; }

Controller::~Controller() { delete model_; }

bool Controller::Calculate(const char* input_expression, const char* input_expression_x) {
    bool return_value = model_->MainFunction(input_expression, input_expression_x);
    if (return_value) {
        result_ = model_->GetResult();
    }
    return return_value;
}
bool Controller::Calculate(const char* input_expression, long double x) {
    bool return_value = model_->MainFunction(input_expression, x);
    if (return_value) {
        result_ = model_->GetResult();
    }
    return return_value;
}

long double Controller::GetResult() { return result_; }

bool Controller::CheckGraphicParameters(const char* x_min_char_str, const char* x_max_char_str,
                                        const char* y_min_char_str, const char* y_max_char_str,
                                        const char* step_char_str, long double& x_min, long double& x_max,
                                        long double& y_min, long double& y_max, long double& step) {
    return model_->CheckGraphicParameters(x_min_char_str, x_max_char_str, y_min_char_str, y_max_char_str,
                                          step_char_str, x_min, x_max, y_min, y_max, step);
}
}  // namespace s21
