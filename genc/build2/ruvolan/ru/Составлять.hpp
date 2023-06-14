// ruvolan/ru/Составлять.s
#pragma once
#include "../st/Глагол.hpp"
namespace ru {
    struct Составлять : st::Глагол {
	Составлять();
	Составлять(Примитив *actual_form);
	virtual void __vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden = false) const override;
	void __vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const;
    };

#ifdef VAS_LIBRARY
    template<typename Stream>
    ::vas::ds<Stream> operator << (::vas::ds<Stream> s, const Составлять &v) {
	::vas::Debdata::Context ctx(*s.s);
	v.__vas_auto_debdata(ctx);
	return s;
    }
#endif
}
