#pragma once
#ifndef DROPLET_H
#define DROPLET

#include <Godot.hpp>
#include <Spatial.hpp>
#include <gdwall.h>
#include <random>
#include <chrono>
#include <SphereShape.hpp>
#include <CollisionShape.hpp>
#include <MeshInstance.hpp>
#include <CollisionObject.hpp>
#include <Mesh.hpp>
#include <SphereMesh.hpp>
#include <KinematicBody.hpp>
#include <KinematicCollision.hpp>
#include <RigidBody.hpp>

namespace godot {

    
    

    class Droplet : public KinematicBody {
        GODOT_CLASS(Droplet, KinematicBody)

    private:
        
        

    public:
        const float width = 2.5;
    const float height = 1.5;
        const float scale = 400;
        const float render_width = scale * width;
        const float render_height = scale * height;
        const int max_particles = 22;
        const float rest_density = 1.0f;
        const float stiffness = 1.5f;
        const float gravity = 1.2f;
        const float particle_spacing = 1.0f / max_particles;
        const float timestep = 0.016;
        const float particle_volume = particle_spacing * particle_spacing;
        const float particle_mass = particle_volume * rest_density;
        const float kernel_range = 1.25f;
        const float KERNEL_CONST = 315.0 / (64.0 * 3 * (powf(kernel_range, 9)));
        const float GRAD_KERNEL_CONST = 15.0 / (M_PI * powf(kernel_range, 6));
        const float viscosity_const = 0.3f;
        const float max_dist =  4.0f;
        float density = 0.0f;
        float viscosity = 0.0f;
        float pressure = 0.0f;
        Vector3 position = Vector3(0.0f, 0.0f, 0.0f);
        Vector3 velocity = Vector3(0.0f, 0.0f, 0.0f);
        Vector3 force = Vector3(0.0f, 0.0f, 0.0f);
        static void _register_methods();
        Ref<SphereShape> droplet_collision;
        Ref<SphereMesh> droplet_mesh;

        Droplet();
        ~Droplet();

        void _init(); // our initializer called by Godot
        void _ready();
        void _process(float delta);
        void _on_body_entered(Node *body);
        float _get_kernel_size();
        bool resting = false;
       
    };
}

#endif
