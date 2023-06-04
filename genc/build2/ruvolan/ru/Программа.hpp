// ruvolan/ru/Программа.s
#pragma once
#include "../st/Существительное.hpp"
namespace ru {
    struct Программа : st::Существительное {
	virtual void __vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden = false) const override;
	void __vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const;
    };

#ifdef VAS_LIBRARY
    template<typename Stream>
    ::vas::ds<Stream> operator << (::vas::ds<Stream> s, const Программа &v) {
	::vas::Debdata::Context ctx(*s.s);
	v.__vas_auto_debdata(ctx);
	return s;
    }
#endif
}
