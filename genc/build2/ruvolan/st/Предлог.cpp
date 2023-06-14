// ruvolan/st/Предлог.s
#include "../../ruvolan.ref.inc"
#include "Предлог.hpp"
namespace st {
    Предлог::Предлог()
	: Слово()
    {
    }

    Предлог::Предлог(Примитив *actual_form)
	: Слово(actual_form)
    {
    }

    void Предлог::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(st::Предлог,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(st::Предлог,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*st::Предлог #" << ((void*)this) << '\n';
		__vas_auto_debdata_fields(ctx);
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }

    void Предлог::__vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const {
	Слово::__vas_auto_debdata_fields(ctx);
    }
}
