#include "Player.h"
#include <SceneTree.hpp>
using namespace godot;

// Déclaration des methodes donnés par godot dans le registre 
void Player::_register_methods() {
	register_method((char*)"_process", &Player::_process);
	register_method("_on_Hitbox_body_entered", &Player::_on_Hitbox_body_entered);
	

}

void Player::_init() {}

Player::Player() {
	velocity = Vector2(0, 0);


}

Player::~Player() {}

void Player::_process(float delta) 
{
	UpdateMotionFromInput();
	move_and_slide(velocity,Vector2(0,0).UP);
}
/*----------------Mouvements du joueur-----------------*/
void Player::UpdateMotionFromInput()
{
	velocity = Vector2(0, 0);
	velocity.y += GRAVITY;

	//Pointeur "_all " de type ->AnimationPlayer

	AnimationPlayer* _all = (AnimationPlayer*)get_node("allanimation");
	
	Input* i = Input::get_singleton();

	//Pointeur "_Flip " de type ->Sprite

	Sprite* _Flip = (Sprite*)get_node("caracter");

	//Condition du Flip du joueur
	if (flip_H == false) {
		_Flip->set_flip_h(0);
	}
	else
		_Flip->set_flip_h(1);

	// input "ui_left" pour aller vers la gauche
	if (i->is_action_pressed("ui_left")) {
		_all->play("walk");
		velocity.x -= speed;
		flip_H = true;

	}
	//input "ui_right" pour aller vers la gauche
	else if (i->is_action_pressed("ui_right")) {
		_all->play("walk");
		velocity.x += speed;
		flip_H = false;

	}
	// Input "jump" pour que le joueur saute 
	if (i->is_action_just_pressed("jump") && is_on_floor()) {
		velocity.y -= jump_Force;
	}
	// Si le joueur n'est pas sur la terre l'animation "jump" apparait
	if (!is_on_floor()) {
		_all->play("jump");

	}
	// Condition si le joueur dépasse une altitude de 1000 il refait la scéne 
	if (get_global_position().y >= 1000)
	{
		get_tree()->reload_current_scene();
	}

	// Condition si le joueur est sur la terre l'animation "idle" apparait
	if (velocity.x == 0 && is_on_floor()) {
		_all->play("idle");
	}
}
// Si le joueur entre dans la zone collisionShape du groupe enemy il meurt et refait la scéne
	void Player::_on_Hitbox_body_entered(Node* body)
	{
		if (body->is_in_group("enemy")) 
		{
			get_tree()->reload_current_scene();
		}
		

	}
	

	
	
	

