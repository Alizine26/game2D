#pragma once
#include <Godot.hpp>
#include<Control.hpp>
#include <SceneTree.hpp>

using namespace godot;

class win : public Control {
	GODOT_CLASS(win, Control)

public:
	// declaration de la methode _on_Replay_pressed dans par godot 
	static void _register_methods() {
		register_method("_on_Replay_pressed", &win::_on_Replay_pressed);
		

	}

	win() {
	}

	~win() {
	}

	void _init() {
	}
	// Si on clique sur le boutton Replay -> redirection vers la scene menuMario.tscn
	void _on_Replay_pressed() {

		get_tree()->change_scene("res://menuMario.tscn");

	}
	


};