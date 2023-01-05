#pragma once
#include <Godot.hpp>
#include<Area2D.hpp>
#include <SceneTree.hpp>

using namespace godot;

class Home2 : public Area2D {
	GODOT_CLASS(Home2, Area2D)

public:
	// Declaration de la methode _on_Area2D_body_entered
	static void _register_methods() {
		register_method("_on_Area2D_body_entered", &Home2::_on_Area2D_body_entered);
	}

	Home2() {
	}

	~Home2() {
	}

	void _init() {
	}

	// Si le joueur entre dans le Area2D du Home2 -> redirection vers la scene win.tscn
	void _on_Area2D_body_entered(Node* body) {
		if (body->is_in_group("player")) {
			get_tree()->change_scene("res://win.tscn");
		}
	}
};

