// ruvolan/st/Существительное.s
#pragma once
#include "Слово.hpp"
namespace st {
    struct Существительное : Слово {
	Существительное();
	Существительное(Примитив *actual_form);
	virtual void __vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden = false) const override;
	void __vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const;
    };

#ifdef VAS_LIBRARY
    template<typename Stream>
    ::vas::ds<Stream> operator << (::vas::ds<Stream> s, const Существительное &v) {
	::vas::Debdata::Context ctx(*s.s);
	v.__vas_auto_debdata(ctx);
	return s;
    }
#endif
}
