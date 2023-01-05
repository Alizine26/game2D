#pragma once
#include<Control.hpp>
#include <SceneTree.hpp>
#include<CanvasLayer.hpp>

using namespace godot;

class canvas : public CanvasLayer{
	GODOT_CLASS(canvas, CanvasLayer)

public:
	static void _register_methods() {
		// declaration de la methode _on_Exit_pressed dans par godot 
		register_method("_on_Exit_pressed", &canvas::_on_Exit_pressed);
	}

	canvas() {
	}

	~canvas() {
	}

	void _init() {
	}
	// Si on clique sur le boutton exit -> redirection vers la scene menuMario.tscn
	void _on_Exit_pressed() {

		get_tree()->change_scene("res://menuMario.tscn");

	}
};
