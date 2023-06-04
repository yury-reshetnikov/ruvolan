// ruvolan/st/Примитив.s
#pragma once
namespace st {
    struct Примитив {
	virtual Примитив *main_form() const;
	virtual void __vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden = false) const;
	void __vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const;
    };

#ifdef VAS_LIBRARY
    template<typename Stream>
    ::vas::ds<Stream> operator << (::vas::ds<Stream> s, const Примитив &v) {
	::vas::Debdata::Context ctx(*s.s);
	v.__vas_auto_debdata(ctx);
	return s;
    }
#endif
}
