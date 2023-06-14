#include "../../ruvolan.ref.inc"
#include "Составить.hpp"
#include "Составлять.hpp"
#include "../st/Примитив.hpp"
namespace ru {
    st::Примитив *Составить::main_form() {
	return new Составлять(this);
    }

    void Составить::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(ru::Составить,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(ru::Составить,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*ru::Составить #" << ((void*)this) << '\n';
		__vas_auto_debdata_fields(ctx);
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }

    void Составить::__vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const {
	st::Совершенный::__vas_auto_debdata_fields(ctx);
    }
}
