// Автор: Юрий Решетников <reshu@mail.ru>

#parse_vas_macro
    auto root = parser.main_data.root_lock()
    auto exp = Vasek::Exp::Manual::shp(std::string())
    // отложить для формирования автоматических классов (формы слов)
    root->deferred_parse.emplace(Vasek::Root::DefaultDeferredPriority,
	[root,exp]() -> void {
	    std::stringstream txt
	    bool first = true
	    Vasek::Data::NamespaceShp ru =
		root->checked_lookup_names({"ru"})->exp_type()
	    for auto &&w : ru->types
		if w.second->is_struct() // отсечь макросы
		    std::string lc = w.first
		    vas::utf8_ru_lc(lc)
		    // #vas::todo_vars lc w.first // *w.second
		    if first : first = false
		    else txt << ','
		    txt << "\n\t{\"" << lc
			<< "\",[]() -> st::Примитив * { return new ru::"
			<< w.first << "; }}"
		    exp->refs.emplace_back(Vasek::Data::BaseNamespace::RefsCategory::refs_code, dynamic_cast<Vasek::Data::BaseNamespace *>(w.second.get()))
	    if !first
		txt << '\n'
		exp->text = txt.str()
	})
    return exp

/*
 * Local Variables:
 * mode: vasilek
 * coding: utf-8-unix
 * tab-width: 8
 * End:
 */
