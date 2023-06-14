// Автор: Юрий Решетников <reshu@mail.ru>

#parse_vas_macro
    auto form = #Vasek::Reader::require(parser, Word)
    parser.cmd_end()
    Vasek::Data::BaseNamespaceShp uph = parser.main_data.up_lock()
    auto s = Vasek::Data::Struct::shp(uph, form->text, fs::directory_entry())
    s->read_source_state = Vasek::PrDone
    uph->types.emplace(form->text, s)
    Vasek::Parser::parse_decls(name_token, *s, ":st::Совершенный")
    Vasek::Parser::parse_decls(name_token, *s,
	#"override st::Примитив *main_form() { return new ${parser.main_data.name}(this); }")
    return Vasek::VasCodeEntityShp()

/*
 * Local Variables:
 * mode: vasilek
 * coding: utf-8-unix
 * tab-width: 8
 * End:
 */
