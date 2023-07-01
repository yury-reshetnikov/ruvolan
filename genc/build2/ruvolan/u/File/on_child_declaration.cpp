// ruvolan/u/File/on_child_declaration.e
#include "../../../ruvolan.macro.ref.inc"
#include "on_child_declaration.hpp"
namespace u {
    void __VASMACRO_File::on_child_declaration::play_vas_event(::Vasek::VasCodeEntityShp owner, ::Vasek::VasOtherEntityShp data) {
	Vasek::Others::EventShpChild::play_vas_event(owner, data);
    }

    void __VASMACRO_File::on_child_declaration::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(u::File::on_child_declaration,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(u::File::on_child_declaration,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*u::File::on_child_declaration #" << ((void*)this) << '\n';
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }
}
