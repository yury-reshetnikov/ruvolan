int main(int argc, char **argv) {
    try {
	if(argc != 2) {
	    throw ::vas::Error(::vas::Error::Pos("ruvolan.a",
		5), // vas::throw
		::vas::Error::Pos(__FILE__, __LINE__), "main", (::vas::dss() << "argc=" << argc).s->str());
	}
	u::Application::shp(argv[1])->build();
	return 0;
    }
    catch(const vas::Error &e) {
	std::cerr << "error: " << e.what() << std::endl << std::flush;
	return 1;
    }
    catch(const std::exception &e) {
	std::cerr << "exception: " << e.what() << std::endl << std::flush;
	return 1;
    }
    catch(...) {
	std::cerr << "unknown error" << std::endl << std::flush;
	return 1;
    }
    return 0;
}
