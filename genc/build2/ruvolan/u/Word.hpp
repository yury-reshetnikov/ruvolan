// ruvolan/u/Word.s
#pragma once
namespace st {
    struct Примитив;
}
namespace u {
    struct Word {
	const char *word;
	std::function<st::Примитив * () > create;
	void dummy(st::Примитив *);
	void __vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden = false) const;
    };

#ifdef VAS_LIBRARY
    template<typename Stream>
    ::vas::ds<Stream> operator << (::vas::ds<Stream> s, const Word &v) {
	::vas::Debdata::Context ctx(*s.s);
	v.__vas_auto_debdata(ctx);
	return s;
    }
#endif
}
