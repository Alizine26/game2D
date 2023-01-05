#pragma once

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <Input.hpp>
#include<AnimationPlayer.hpp>
#include<Sprite.hpp>
#include<AnimatedSprite.hpp>
#include<Area2D.hpp>


namespace godot {
	class Player : public KinematicBody2D 
	{
	
	// structure Godot
	private:
		GODOT_CLASS(Player, KinematicBody2D)

	// Methodes
	public:
		static void _register_methods();
		void _init();
		void _on_Hitbox_body_entered(Node* body);
		void _process(float delta);
		
		
		Player();
		~Player();


	//  Variables du charactere 
	public:
		const int speed = 200;
		const int GRAVITY = 400;
		const int jump_Force = 8000;
		const int Max_Fall_speed = 100;
		bool flip_H = false;
		bool flip_V = false;
		
		
	private:
		Vector2 velocity;
		bool facingright;


	// methodes du jeu
	public:
		void UpdateMotionFromInput();
		void global_position(Node* body);
		
	private:




	};
}
