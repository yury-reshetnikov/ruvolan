// ruvolan/u.n
#include "../ruvolan.ref.inc"
#include "u.ns.inc"
namespace u {

    const Word words[] = {
	{"для",[]() -> st::Примитив * { return new ru::Для; }},
	{"консольный",[]() -> st::Примитив * { return new ru::Консольный; }},
	{"программа",[]() -> st::Примитив * { return new ru::Программа; }},
	{"составлять",[]() -> st::Примитив * { return new ru::Составлять; }}
};
}
