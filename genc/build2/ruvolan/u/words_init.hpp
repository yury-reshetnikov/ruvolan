// ruvolan/u/words_init.m
#pragma once
namespace u {
    struct words_init {
	static ::Vasek::VasCodeEntityShp parse_vas_macro(::Vasek::Parser::Base &parser, ::Vasek::Token::BaseShp name_token);
	void __vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden = false) const;
    };

#ifdef VAS_LIBRARY
    template<typename Stream>
    ::vas::ds<Stream> operator << (::vas::ds<Stream> s, const words_init &v) {
	::vas::Debdata::Context ctx(*s.s);
	v.__vas_auto_debdata(ctx);
	return s;
    }
#endif
}
