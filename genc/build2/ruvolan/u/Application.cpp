// ruvolan/u/Application.s
#include "../../ruvolan.ref.inc"
#include "Application.hpp"
namespace u {
    void Application::build() {
	std::cerr << "TODO ruvolan/u/Application.s "
	    "6" // vas::warn
	    " build " << std::endl << std::flush;
    }

    Application::Application(std::string src_file_name)
	: File(src_file_name)
    {
    }

    ApplicationShp Application::shared_from_this() {
	return std::enable_shared_from_this<File >::shared_from_this();
    }

    ApplicationShp Application::shp(std::string src_file_name) {
	ApplicationShp __shp_result(new Application(src_file_name));
	if(__shp_result) {
	    return __shp_result;
	}
	else {
	    throw ::vas::Error(::vas::Error::Pos("-",
		1), // vas::throw
		::vas::Error::Pos(__FILE__, __LINE__), "shp", (::vas::dss() << "new failed in " << __PRETTY_FUNCTION__).s->str());
	}
    }

    void Application::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(u::Application,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(u::Application,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*u::Application #" << ((void*)this) << '\n';
		__vas_auto_debdata_fields(ctx);
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }

    void Application::__vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const {
	File::__vas_auto_debdata_fields(ctx);
    }
}
