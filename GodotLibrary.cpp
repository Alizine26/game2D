// Les fichiers point h du projet 
#include "Player.h"
#include "enemy.h"
#include "Home.h"
#include "menu.h"
#include "pause.h"
#include "enemy2.h"
#include "Home2.h"
#include "win.h"

//Déclaration de la fonction godot_gdnative_init() avec l'attribut "extern C" 
using namespace godot;

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o) {
	Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o) {
	Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle) {

	//déclaration de toutes les classes utilisées

	Godot::nativescript_init(handle);
	register_class<Player>();
	register_class<enemy>();
	register_class<Home>();
	register_class<menu>();
	register_class<canvas>();
	register_class<enemy2>();
	register_class<Home2>();
	register_class<win>();

	
}
	
