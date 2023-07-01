#include "ruvolan.macro.ref.inc"
#include "ruvolan/ru/винительный_единственное.hpp"
#include "ruvolan/ru/винительный_женский.hpp"
#include "ruvolan/ru/совершенный.hpp"
#include "ruvolan/u/File/on_child_declaration.hpp"
#include "ruvolan/u/words_init.hpp"
struct Name { const char *const name; const void *const ptr; const void *const event; };
const Name names[12] = {
    { "ru", (const void *const)(names + 3), NULL},
    { "u", (const void *const)(names + 7), NULL},
    { NULL, NULL, NULL },
    { "винительный_единственное", (const void *const)&ru::винительный_единственное::parse_vas_macro, NULL},
    { "винительный_женский", (const void *const)&ru::винительный_женский::parse_vas_macro, NULL},
    { "совершенный", (const void *const)&ru::совершенный::parse_vas_macro, NULL},
    { NULL, NULL, NULL },
    { "File", (const void *const)(names + 10), NULL},
    { "words_init", (const void *const)&u::words_init::parse_vas_macro, NULL},
    { NULL, NULL, NULL },
    { "on_child_declaration", NULL, (const void *const)&u::__VASMACRO_File::on_child_declaration::play_vas_event},
    { NULL, NULL, NULL },
};
extern "C" bool find(void *base, const char *name, void **childs, void **macro, void **event) {
    const Name *ptr, *end = names + 12;
    if(base) {
	ptr = (const Name *)base;
	if(ptr < names || ptr >= end) return false;
    }
    else if(name) ptr = names;
    else if(childs) {
	*childs = (void *)"ruvolan";
	return true;
    }
    else return false;
    while(ptr < end && ptr->name) if(strcmp(ptr->name, name) == 0) {
	if(ptr->ptr > ptr && ptr->ptr < end) {
	    if(!childs) return false;
	    *childs = (void*)ptr->ptr;
	    if(macro) *macro = NULL;
	    if(event) *event = NULL;
	}
	else if(ptr->event && event) {
	    if(childs) *childs = NULL;
	    if(macro) *macro = (void*)ptr->ptr;
	    *event = (void*)ptr->event;
	}
	else {
	    if(!macro || !ptr->ptr) return false;
	    if(childs) *childs = NULL;
	    *macro = (void*)ptr->ptr;
	    if(event) *event = NULL;
	}
	return true;
    }
    else ++ptr;
    return false;
}
