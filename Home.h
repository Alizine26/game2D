#pragma once
#include <Godot.hpp>
#include<Area2D.hpp>
#include <SceneTree.hpp>

using namespace godot;

class Home : public Area2D {
	GODOT_CLASS(Home, Area2D)

public:
	// declaration des  methodes _on_Play_pressed et _on_Quit_pressed dans par godot 

	static void _register_methods() {
		register_method("_on_Area2D_body_entered", &Home::_on_Area2D_body_entered);
	}
	//constructeur 
	Home() {
	}
	//Deconstructeur 
	~Home() {
	}

	void _init() {
	}
	// Si le joueur entre dans le Area2D du Home -> redirection vers la scene level2.tscn

	void _on_Area2D_body_entered(Node* body) {
		if (body->is_in_group("player")) {
			get_tree()->change_scene("res://level2.tscn");
		}
	}
};
