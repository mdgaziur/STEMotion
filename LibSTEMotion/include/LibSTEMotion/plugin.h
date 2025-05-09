//
// Created by mdgaziur001 on 3/31/25.
//

#ifndef PLUGIN_H
#define PLUGIN_H

#define DEFINE_PLUGIN(name, init, simulator) \
    const char *STEMOTION_PLUGIN_NAME = #name; \
    \
    void STEMOTION_PLUGIN_INIT(SimulationParams *simulation_params) { \
        #init(); \
    } \
    void STEMOTION_PLUGIN_SIMULATOR(SimulationParams *simulation_params, DrawQueue *draw_queue) { \
        #simulator(simulation_params, draw_queue); \
    }

#endif //PLUGIN_H
