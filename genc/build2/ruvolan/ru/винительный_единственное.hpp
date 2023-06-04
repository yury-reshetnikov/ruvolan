// ruvolan/ru/винительный_единственное.m
#pragma once
namespace ru {
    struct винительный_единственное {
	static ::Vasek::VasCodeEntityShp parse_vas_macro(::Vasek::Parser::Base &parser, ::Vasek::Token::BaseShp name_token);
	void __vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden = false) const;
    };

#ifdef VAS_LIBRARY
    template<typename Stream>
    ::vas::ds<Stream> operator << (::vas::ds<Stream> s, const винительный_единственное &v) {
	::vas::Debdata::Context ctx(*s.s);
	v.__vas_auto_debdata(ctx);
	return s;
    }
#endif
}
