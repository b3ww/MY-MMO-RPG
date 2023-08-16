/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski
** File description:
** wcsv_request
*/

#include "wcsv.h"

static int get_fi(char **format_line, char *to_find)
{
    for (int i = 0; format_line[i]; i++) {
        if (!strcmp(format_line[i], to_find))
            return i;
    }
    return -1;
}

static void *case_value(wcsv_t *parse, wreq_t pr)
{
    int findex = 0;
    char **tmp = NULL;

    switch (pr.want_type) {
    case LINE: return get_line_with_value(parse, pr.know);
    case COLUMN: return get_column_with_value(parse, pr.know);
    case VALUE: return NULL;
    case LFORMAT: tmp = get_line_with_value(parse, pr.know);
        findex = get_fi(parse->l_format, pr.want);
        return findex == -1 || !tmp ? NULL : tmp[findex];
    case CFORMAT: tmp = get_column_with_value(parse, pr.know);
        findex = get_fi(parse->c_format, pr.want);
        return findex == -1 || !tmp ? NULL : tmp[findex];
    default: return NULL;
    }
}

static void *case_line(wcsv_t *parse, wreq_t pr)
{
    int findex = 0;
    char **tmp = NULL;

    switch (pr.want_type) {
        case LINE: return pr.know;
        case COLUMN: return NULL;
        case VALUE: return pr.want;
        case LFORMAT: findex = get_fi(parse->l_format, pr.want);
            tmp = pr.know;
            return findex == -1 ? NULL : tmp[findex];
        case CFORMAT: return NULL;
        default: return NULL;
    }
}

static void *case_column(wcsv_t *parse, wreq_t pr)
{
    int format_index = 0;
    char **tmp = NULL;

    switch (pr.want_type) {
        case LINE: return NULL;
        case COLUMN: return pr.know;
        case VALUE: return pr.want;
        case LFORMAT: return NULL;
        case CFORMAT: format_index = get_fi(parse->c_format, pr.want);
            tmp = pr.know;
            return tmp[format_index];
        default: return NULL;
    }
}

void *wcsv_get(wcsv_t *parse, wreq_t parse_request)
{
    switch (parse_request.know_type) {
        case LINE: return case_line(parse, parse_request);
        case COLUMN: return case_column(parse, parse_request);
        case VALUE: return case_value(parse, parse_request);
        default: return NULL;
    }
}
