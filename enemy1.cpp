#include"enemy.h"
#include <SceneTree.hpp>
using namespace godot;
// Déclaration des methodes de l'enemy2 donnés par godot dans le registre 
void enemy::_register_methods() {
    register_method((char*)"_process", &enemy::_process);
    register_method("_on_enemy_body_entered", &enemy::_on_enemy_body_entered);
    
}

void enemy::_init() {}
//Contructeur
enemy::enemy() {



}
//Décontructeur
enemy::~enemy() {}


void enemy::_process(float delta)
{// Pointeur "_a" de type "AnimationPlayer" 
    AnimationPlayer* _a = (AnimationPlayer*)get_node("animplayer");
   
    Sprite* _ene = (Sprite*)get_node("enemi");
    /*--------Mouvement enemy1-----------*/
    move_and_slide(velocity, Vector2(0, 0).UP);

    velocity = Vector2(0, 0);

    velocity.y += GRAVITY;

    velocity.x -= speed * dir;
    _a->play("moove");
    //Condition si l'enemy1 trouve un mur et change de direction 

    if (is_on_wall()) {
        dir *= -1;
        if (dir < 0) {
            _ene->set_flip_h(0);
        }
        else
            _ene->set_flip_h(1);
    }
 
}
// si le joueur entre en collision avec la zone collisionShap  l'enemy1 meurt  
    void enemy::_on_enemy_body_entered(Node * body) {
       
        if (body->is_in_group("player")) {
            
            queue_free();
        }
    }
