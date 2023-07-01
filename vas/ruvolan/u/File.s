// Автор: Юрий Решетников <reshu@mail.ru>

: std::enable_shared_from_this<File>

vas::File src

#vas::constructor(std::string src_file_name)
    : src(src_file_name, O_RDONLY)
    ;

/*
 * Local Variables:
 * mode: vasilek
 * coding: utf-8-unix
 * tab-width: 8
 * End:
 */
