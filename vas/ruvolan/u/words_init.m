// Автор: Юрий Решетников <reshu@mail.ru>

#parse_vas_macro
    auto root = parser.main_data.root_lock()
    auto exp = Vasek::Exp::Manual::shp(std::string())
    // отложить для формирования автоматических классов (формы слов)
    root->deferred_parse.emplace(Vasek::Root::DefaultDeferredPriority,
	[root,exp]() -> void {
	    Vasek::Data::NamespaceShp ru =
		root->checked_lookup_names({"ru"})->exp_type()
	    for auto &&w : ru->types
		if w.second->is_struct() // отсечь макросы
		    std::string lc = w.first
		    boost::to_lower(lc)
		    #vas::todo_vars lc w.first // *w.second
	})
    return exp

/*
 * Local Variables:
 * mode: vasilek
 * coding: utf-8-unix
 * tab-width: 8
 * End:
 */
