// ruvolan/u/File/on_child_declaration.e
#pragma once
#include "../File.macro.hpp"
namespace u {
    struct __VASMACRO_File::on_child_declaration {
	static void play_vas_event(::Vasek::VasCodeEntityShp owner, ::Vasek::VasOtherEntityShp data);
	void __vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden = false) const;
    };

#ifdef VAS_LIBRARY
    template<typename Stream>
    ::vas::ds<Stream> operator << (::vas::ds<Stream> s, const __VASMACRO_File::on_child_declaration &v) {
	::vas::Debdata::Context ctx(*s.s);
	v.__vas_auto_debdata(ctx);
	return s;
    }
#endif
}
