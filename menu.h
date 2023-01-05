
#pragma once
#include <Godot.hpp>
#include<Control.hpp>
#include <SceneTree.hpp>

using namespace godot;

class menu : public Control {
	GODOT_CLASS(menu, Control)

public:
	static void _register_methods() {

	// declaration des  methodes _on_Play_pressed et _on_Quit_pressed dans par godot 

		register_method("_on_Play_pressed", &menu::_on_Play_pressed);
		register_method("_on_Quit_pressed", &menu::_on_Quit_pressed);
		
	}

	menu() {
	}
	
	~menu() {
	}

	void _init() {
	}
	// Si on clique sur le boutton Play -> redirection vers la scene menuMario.tscn
	void _on_Play_pressed() {

		get_tree()->change_scene("res://level1.tscn");
	}
    // Si on clique sur le boutton quit -> redirection vers la scene menuMario.tscn	
	void _on_Quit_pressed() {

		get_tree()->quit();

	}
	
};

