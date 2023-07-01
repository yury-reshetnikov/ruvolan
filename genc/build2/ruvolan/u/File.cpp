// ruvolan/u/File.s
#include "../../ruvolan.ref.inc"
#include "File.hpp"
namespace u {
    File::File(std::string src_file_name)
	: src(src_file_name, O_RDONLY)
    {
    }

    void File::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(u::File,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(u::File,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*u::File #" << ((void*)this) << '\n';
		__vas_auto_debdata_fields(ctx);
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }

    void File::__vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const {
    }
}
