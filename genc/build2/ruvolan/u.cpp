// ruvolan/u.n
#include "../ruvolan.ref.inc"
#include "ru/Для.hpp"
#include "ru/Консольный.hpp"
#include "ru/Программа.hpp"
#include "ru/Составлять.hpp"
#include "u.ns.inc"
namespace u {

    const Word words[] = {
	{"для",[]() -> st::Примитив * { return new ru::Для; }},
	{"консольный",[]() -> st::Примитив * { return new ru::Консольный; }},
	{"программа",[]() -> st::Примитив * { return new ru::Программа; }},
	{"составить",[]() -> st::Примитив * { return new ru::Составить; }},
	{"составлять",[]() -> st::Примитив * { return new ru::Составлять; }}
};
}
