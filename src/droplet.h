#ifndef DROPLET_H
#define DROPLET

#include <Godot.hpp>
#include <Spatial.hpp>
#include <Area.hpp>
#include <gdwall.h>
#include <random>
#include <chrono>
#include <SphereShape.hpp>
#include <CollisionShape.hpp>
#include <CollisionObject.hpp>

namespace godot {

    enum {sphere, wall};
    const unsigned int max_spd = 10;
    const unsigned int min_spd = -10;
    const unsigned int max_dir = 100;
    const unsigned int min_dir = -100;
    const real_t upper = 15.0;
    const real_t lower = -15.0;

    class Droplet : public Spatial {
        GODOT_CLASS(Droplet, Spatial)

    private:
        bool bounce;
        float spd;
        float x_dir;
        float y_dir;
        float z_dir;
        float x_sign;
        float y_sign;
        float z_sign;
        

    public:
        static void _register_methods();

        Droplet();
        ~Droplet();

        void _init(); // our initializer called by Godot
        void _ready();
        void _on_area_entered(Area *test);
        void _process(float delta);
        void _bounce_ball(Vector3 N);
        Vector3 _get_velocity();
    };
}

#endif