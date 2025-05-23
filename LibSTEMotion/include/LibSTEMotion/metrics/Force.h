//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef FORCE_H
#define FORCE_H
#include <string>

#include "BaseQuantity.h"
#include "metrics.h"

namespace STEMotion {

class Force final : public BaseQuantity {
    f64 force;
    Metric metric;

    const char *units[3] = { "N", "dyn", "lbf" };
public:
    Force(std::string name, f64 force, Metric metric);
    void to_metric(Metric metric) override;
    [[nodiscard]] f64 display() const override;
    [[nodiscard]] std::string unit() const override {
        return units[metric];
    }

    [[nodiscard]] const char** get_units() override {
        return units;
    }
private:
    static f64 to_mks(f64 force, Metric metric);
};

} // STEMotion

#endif //FORCE_H
