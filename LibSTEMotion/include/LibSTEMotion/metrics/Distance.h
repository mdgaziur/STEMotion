//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef DISTANCE_H
#define DISTANCE_H
#include <string>

#include "BaseQuantity.h"
#include "metrics.h"


namespace STEMotion {

class Distance final : public BaseQuantity {
    f64 distance;
    Metric metric;

    const char *units[3] = { "m", "cm", "ft" };
public:
    Distance(std::string name, f64 distance, Metric metric);
    void to_metric(Metric metric) override;
    [[nodiscard]] f64 display() const override;
    [[nodiscard]] std::string unit() const override {
        return units[metric];
    }

    [[nodiscard]] const char** get_units() override {
        return units;
    }
private:
    static f64 to_mks(f64 distance, Metric metric);
};

}


#endif //DISTANCE_H
