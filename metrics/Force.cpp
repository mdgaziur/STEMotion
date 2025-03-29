//
// Created by mdgaziur001 on 3/29/25.
//

#include "Force.h"

#include <utility>

namespace STEMotion {
    Force::Force(std::string name, f64 force, Metric metric) : BaseQuantity(std::move(name)) {
        this->force = to_mks(force, metric);
        this->metric = metric;
    }

    void Force::to_metric(Metric metric) {
        this->metric = metric;
    }

    f64 Force::display() const {
        switch (metric) {
            case MKS:
                return force;
            case CGS:
                return force / 10e-5;
            case FPS:
                return force / 0.1382549544;
            default:
                return -1;
        }
    }

    std::string Force::unit() const {
        switch (metric) {
            case MKS:
                return "N";
            case CGS:
                return "dyn";
            case FPS:
                return "lbf";
            default:
                return "";
        }
    }

    f64 Force::to_mks(f64 force, Metric metric) {
        switch (metric) {
            case MKS:
                return force;
            case CGS:
                return force * 10e-5;
            case FPS:
                return force * 0.1382549544;
            default:
                return -1;
        }
    }
} // STEMotion