#pragma once
#pragma once
#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include<AnimationPlayer.hpp>
#include<Sprite.hpp>
#include<Vector2.hpp>



namespace godot {
	class enemy : public KinematicBody2D
	{

		// Godot structure
	private:
		GODOT_CLASS(enemy, KinematicBody2D)
	

	public:
		static void _register_methods();
		void _init();
		void _process(float delta);
		void _on_enemy_body_entered(Node* body);
		

		enemy();
		~enemy();
	public:
		// variables

		const int speed = 100;
		const int GRAVITY = 30;
		 int dir = -1;
		bool hit_wall = false;
		bool hit_player = false;
		bool die = true;
		bool flip_H = false;
		bool flip_V = false;


	private:
		Vector2 velocity;
	};
}