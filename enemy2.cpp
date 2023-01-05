#include"enemy2.h"
#include <SceneTree.hpp>
using namespace godot;
// Déclaration des methodes de l'enemy2 donnés par godot dans le registre 
void enemy2::_register_methods() {
    register_method((char*)"_process", &enemy2::_process);
    register_method("_on_enemy_body_entered", &enemy2::_on_Area2D_body_entered);

}

void enemy2::_init() {}
//Contructeur
enemy2::enemy2() {

}
//Destructeur
enemy2::~enemy2() {}


void enemy2::_process(float delta)
{// Pointeur "_a" de type "AnimationPlayer" 
    AnimationPlayer* _a = (AnimationPlayer*)get_node("animationenemy2");

   //Mouvements enemy2 suivant l'axe Y
    move_and_slide(velocity, Vector2(0, 0).UP);

    velocity = Vector2(0, 0);

    velocity.y -= speed * dir;

    velocity.y += GRAVITY;

    // Animation "eat"
    _a->play("eat");

}
// Si le joueur entre dans la zone collisionShape du groupe enemy il meurt et refait la scéne

void enemy2::_on_Area2D_body_entered(Node* body) {
 
    if (body->is_in_group("player")) {

        get_tree()->reload_current_scene();
    }
}
