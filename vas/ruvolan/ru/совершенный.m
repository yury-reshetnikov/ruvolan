// Автор: Юрий Решетников <reshu@mail.ru>

#parse_vas_macro
    auto form = #Vasek::Reader::require(parser, Word)
    parser.cmd_end()
    auto s = Vasek::Data::Struct::shp(parser.main_data.up_lock(),
	form->text, fs::directory_entry())
    #vas::todo_vars form->text s->qname()
    return Vasek::VasCodeEntityShp()

/*
 * Local Variables:
 * mode: vasilek
 * coding: utf-8-unix
 * tab-width: 8
 * End:
 */
