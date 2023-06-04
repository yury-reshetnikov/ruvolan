// ruvolan/st/Слово.s
#include "../../ruvolan.ref.inc"
#include "Слово.hpp"
namespace st {
    Слово::Слово()
	: actual_form(this)
    {
    }

    Слово::Слово(Примитив *actual_form)
	: actual_form(actual_form)
    {
    }

    void Слово::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(st::Слово,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(st::Слово,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*st::Слово #" << ((void*)this) << '\n';
		__vas_auto_debdata_fields(ctx);
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }

    void Слово::__vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const {
	Примитив::__vas_auto_debdata_fields(ctx);
	std::string indent(ctx.indent());
	ctx.path.back() = "actual_form";
	ctx.out << indent << "actual_form: ";
	if(this->actual_form) this->actual_form->__vas_auto_debdata(ctx); else ctx.out << '0';
	ctx.out << ",\n";
    }
}
