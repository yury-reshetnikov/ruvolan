// ruvolan/src0/st/Primitive.hpp

namespace st {
    struct Primitive {
	struct Form { // не путать с ru::Form - формой в общем виде
	    // для представлений разных форм слова, в том числе склонений, времён и падежей
	};
	virtual const char *main_form() const { return "примитив"; }
    };
}
