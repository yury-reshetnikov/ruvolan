// ruvolan/u/File.s
#pragma once
namespace u {
    struct File : std::enable_shared_from_this<File > {
	vas::File src;
	File(std::string src_file_name);
	virtual void __vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden = false) const;
	void __vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const;
    };

#ifdef VAS_LIBRARY
    template<typename Stream>
    ::vas::ds<Stream> operator << (::vas::ds<Stream> s, const File &v) {
	::vas::Debdata::Context ctx(*s.s);
	v.__vas_auto_debdata(ctx);
	return s;
    }
#endif
}
