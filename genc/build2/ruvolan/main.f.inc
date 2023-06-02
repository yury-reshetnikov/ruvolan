int main(int argc, char **argv) {
    try {
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
