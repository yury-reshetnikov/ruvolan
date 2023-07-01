// ruvolan/u/Application.s
#pragma once
#include "../u.ns.inc"
#include "File.hpp"
namespace u {
    struct Application : File {
	typedef ::vas::DerivedSharedPtr<Application, ::u::File > Shp;
	void build();
	Application(std::string src_file_name);
	ApplicationShp shared_from_this();
	static ApplicationShp shp(std::string src_file_name);
	virtual void __vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden = false) const override;
	void __vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const;
    };

#ifdef VAS_LIBRARY
    template<typename Stream>
    ::vas::ds<Stream> operator << (::vas::ds<Stream> s, const Application &v) {
	::vas::Debdata::Context ctx(*s.s);
	v.__vas_auto_debdata(ctx);
	return s;
    }
#endif
}
