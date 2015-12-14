#include "types.hpp"
#include "client\client.hpp"
#include "client_types.hpp"
#include <assert.h>

#define INTERNAL_TAG 0x0000dede

namespace intercept {
    namespace types {
        uintptr_t game_data_string::type_def;
        uintptr_t game_data_string::data_type_def;

        uintptr_t game_data_number::type_def;
        uintptr_t game_data_number::data_type_def;

        uintptr_t game_data_array::type_def;
        uintptr_t game_data_array::data_type_def;

        uintptr_t game_data_bool::type_def;
        uintptr_t game_data_bool::data_type_def;

        uintptr_t game_data_code::type_def;
        uintptr_t game_data_code::data_type_def;

        uintptr_t game_data_group::type_def;
        uintptr_t game_data_group::data_type_def;

        uintptr_t game_data_config::type_def;
        uintptr_t game_data_config::data_type_def;

        uintptr_t game_data_control::type_def;
        uintptr_t game_data_control::data_type_def;

        uintptr_t game_data_display::type_def;
        uintptr_t game_data_display::data_type_def;

        uintptr_t game_data_location::type_def;
        uintptr_t game_data_location::data_type_def;

        uintptr_t game_data_script::type_def;
        uintptr_t game_data_script::data_type_def;

        uintptr_t game_data_side::type_def;
        uintptr_t game_data_side::data_type_def;

        uintptr_t game_data_text::type_def;
        uintptr_t game_data_text::data_type_def;

        uintptr_t game_data_team::type_def;
        uintptr_t game_data_team::data_type_def;

        uintptr_t game_data_namespace::type_def;
        uintptr_t game_data_namespace::data_type_def;

        uintptr_t game_data_object::type_def;
        uintptr_t game_data_object::data_type_def;



        uintptr_t rv_game_value::__vptr_def;



        std::string rv_string::string() {
            return std::string((char *)&char_string);
        }

        value_type op_value_entry::type() {
            if (single_type != NULL) {
                return{ single_type->type_name->string() };
            }
            else {
                return{
                    compound_type->types->first->type_name->string(),
                    compound_type->types->second->type_name->string()
                };
            }
        }

        std::string op_value_entry::type_str() {
            if (single_type != NULL) {
                return single_type->type_name->string();
            }
            else {
                return
                    compound_type->types->first->type_name->string() + "_" +
                    compound_type->types->second->type_name->string();
            }
        }

        game_data_number::game_data_number() {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            number = 0.0f;
        }

        game_data_number::game_data_number(float val_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            number = val_;
        }

        game_data_number::game_data_number(const game_data_number & copy_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            number = copy_.number;
        }

        game_data_number::game_data_number(game_data_number && move_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = move_.ref_count_internal;
            number = move_.number;
        }

        game_data_number & game_data_number::operator=(const game_data_number & copy_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            number = copy_.number;
            return *this;
        }

        game_data_number & game_data_number::operator=(game_data_number && move_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = move_.ref_count_internal;
            number = move_.number;
            return *this;
        }

        game_data_bool::game_data_bool() {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            val = false;
        }

        game_data_bool::game_data_bool(bool val_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            val = val_;
        }

        game_data_bool::game_data_bool(const game_data_bool & copy_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            val = copy_.val;
        }

        game_data_bool::game_data_bool(game_data_bool && move_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = move_.ref_count_internal;
            val = move_.val;
        }

        game_data_bool & game_data_bool::operator=(const game_data_bool & copy_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            val = copy_.val;
            return *this;
        }

        game_data_bool & game_data_bool::operator=(game_data_bool && move_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = move_.ref_count_internal;
            val = move_.val;
            return *this;
        }

        game_data_string::game_data_string() {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            raw_string = allocate_string(128);
            raw_string->length = 128;
            raw_string->ref_count_internal = 1;
        }

        game_data_string::game_data_string(std::string str_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            raw_string = allocate_string(str_.length() + 1);
            memcpy(&raw_string->char_string, str_.c_str(), str_.length() + 1);
            raw_string->length = str_.length() + 1;
            raw_string->ref_count_internal = 1;
        }

        game_data_string::game_data_string(const game_data_string & copy_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            raw_string = allocate_string(copy_.raw_string->length);
            memcpy(&raw_string->char_string, &copy_.raw_string->char_string, copy_.raw_string->length);
            raw_string->length = copy_.raw_string->length;
            raw_string->ref_count_internal = 1;
        }

        game_data_string::game_data_string(game_data_string && move_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = move_.ref_count_internal;
            free_string(raw_string);
            raw_string = move_.raw_string;
            move_.raw_string = nullptr;
        }

        game_data_string & game_data_string::operator=(const game_data_string & copy_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            raw_string = allocate_string(copy_.raw_string->length);
            memcpy(&raw_string->char_string, &copy_.raw_string->char_string, copy_.raw_string->length);
            raw_string->length = copy_.raw_string->length;
            raw_string->ref_count_internal = 1;
            return *this;
        }

        game_data_string & game_data_string::operator=(game_data_string && move_)
        {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = move_.ref_count_internal;
            free_string(raw_string);
            raw_string = move_.raw_string;
            move_.raw_string = nullptr;
            return *this;
        }

        game_data_string::~game_data_string()
        {
            if (raw_string)
                free_string(raw_string);
        }


        game_data_array::game_data_array() {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            length = 0;
            max_size = 0;
            data = nullptr;
        }

        game_data_array::game_data_array(size_t size_) {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            data = new game_value[size_];
            length = size_;
            max_size = size_;
        }

        game_data_array::game_data_array(std::initializer_list<game_value> init_) {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            data = new game_value[init_.size()];
            length = init_.size();
            max_size = init_.size();
            size_t i = 0;
            for (auto it = init_.begin(); it != init_.end(); ++it) {
                data[i++] = *it;
            }
        }

        game_data_array::game_data_array(const game_data_array & copy_) {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            length = copy_.length;
            max_size = copy_.max_size;
            data = new game_value[length];
            for (size_t i = 0; i < length; ++i)
                data[i] = copy_.data[i];
        }

        game_data_array::game_data_array(game_data_array && move_) {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            data = move_.data;
            length = move_.length;
            max_size = move_.max_size;
            move_.data = nullptr;
        }

        game_data_array & game_data_array::operator = (const game_data_array &copy_) {
            type = type_def;
            data_type = data_type_def;
            ref_count_internal = INTERNAL_TAG;
            length = copy_.length;
            data = new game_value[length];
            for (size_t i = 0; i < length; ++i)
                data[i] = copy_.data[i];
            return *this;
        }

        game_data_array & game_data_array::operator = (game_data_array &&move_) {
            if (this == &move_)
                return *this;
            if (data)
                delete[] data;
            data = move_.data;
            length = move_.length;
            max_size = move_.max_size;
            move_.data = nullptr;
            return *this;
        }

        game_data_array::~game_data_array() {
            if (data)
                delete[] data;
        }

        game_value::game_value() {
            _rv_data.data = nullptr;
        }

        void game_value::copy(const game_value & copy_) {
            _rv_data.__vptr = copy_._rv_data.__vptr;
            if (copy_._rv_data.data) {
                if (copy_._rv_data.data->type == game_data_number::type_def) {
                    _rv_data.data = new game_data_number();
                    ((game_data_number *)_rv_data.data)->operator=(*((game_data_number *)copy_._rv_data.data));
                }
                else if (copy_._rv_data.data->type == game_data_bool::type_def) {
                    _rv_data.data = new game_data_bool();
                    ((game_data_bool *)_rv_data.data)->operator=(*((game_data_bool *)copy_._rv_data.data));
                }
                else if (copy_._rv_data.data->type == game_data_array::type_def) {
                    _rv_data.data = new game_data_array();
                    ((game_data_array *)_rv_data.data)->operator=(*((game_data_array *)copy_._rv_data.data));
                }
                else if (copy_._rv_data.data->type == game_data_string::type_def) {
                    _rv_data.data = new game_data_string();
                    ((game_data_string *)_rv_data.data)->operator=(*((game_data_string *)copy_._rv_data.data));
                }
                else {
                    _rv_data.data = copy_._rv_data.data;
                }
            }
        }

        game_value::game_value(const game_value & copy_) {
            copy(copy_);
        }

        game_value::game_value(game_value && move_) {
            _rv_data.__vptr = move_._rv_data.__vptr;
            _rv_data.data = move_._rv_data.data;
            move_._rv_data.data = nullptr;
        }

        game_value::game_value(rv_game_value internal_)
        {
            _rv_data.__vptr = internal_.__vptr;
            _rv_data.data = (game_data *)internal_.data;
        }

        game_value::game_value(float val_)
        {
            _rv_data.data = new game_data_number(val_);
        }

        game_value::game_value(bool val_)
        {
            _rv_data.data = new game_data_bool(val_);
        }

        game_value::game_value(std::string &val_)
        {
            _rv_data.data = new game_data_string(val_);
        }

        game_value::game_value(const char *val_)
        {
            _rv_data.data = new game_data_string(val_);
        }

        game_value::game_value(std::initializer_list<game_value> list_)
        {
            _rv_data.data = new game_data_array(list_);
        }

        game_value::game_value(vector3 & vec_)
        {
            _rv_data.data = new game_data_array({ vec_.x, vec_.y, vec_.z });
        }

        game_value::game_value(vector2 & vec_)
        {
            _rv_data.data = new game_data_array({ vec_.x, vec_.y });
        }
        game_value::game_value(internal_object internal_)
        {
            _rv_data.data = internal_.value->value._rv_data.data;
            _rv_data.__vptr = internal_.value->value._rv_data.__vptr;
        }
        game_value::~game_value() {
            _free();
        }

        void game_value::_free()
        {
            // Ghetto superstar...
            if (_rv_data.data && _rv_data.data->ref_count_internal == INTERNAL_TAG) {
                /*
                 We have no virtual tables because we need to keep the internal games'
                 memory structure intact, so we gotta do it ourselves.

                 Any game_data types that allocate their own memory need to have their
                 destructor called here before we delete the pointer.
                */
                if (_rv_data.data && _rv_data.data->type == game_data_array::type_def)
                    static_cast<game_data_array *>(_rv_data.data)->~game_data_array(); // ... that is what you are.
                else if (_rv_data.data && _rv_data.data->type == game_data_string::type_def)
                    static_cast<game_data_string *>(_rv_data.data)->~game_data_string(); // ... that is what you are.
                if (_rv_data.data)
                    delete _rv_data.data;
            }
            else {
                /*
                 How this works? We need to free data allocated in the engine process in the engine
                 process. So we know it isn't our own created data because we tag with INTERNAL_TAG
                 (0x0000dede) and we pass back the game_value to the engine. The engine then copies
                 the ptr address of the raw rv_game_value to its pool of game_values to delete later
                 and we can just null out the ptr here, effectively freeing the memory in the context
                 of the object (the actual memory will be freed later by the game process).
                */
                if (_rv_data.data && (
                    _rv_data.data->type == game_data_number::type_def ||
                    _rv_data.data->type == game_data_bool::type_def ||
                    _rv_data.data->type == game_data_array::type_def ||
                    _rv_data.data->type == game_data_string::type_def
                    )) {
                    client::host::functions.free_value(this);
                    _rv_data.data = nullptr;
                }
            }
        }

        game_value & game_value::operator = (const game_value &copy_) {
            copy(copy_);
            return *this;
        }
        game_value & game_value::operator = (game_value &&move_) {
            if (this == &move_)
                return *this;
            if (_rv_data.data) // this needs to be properly freed from where it came.
                _free();
            _rv_data.__vptr = move_._rv_data.__vptr;
            _rv_data.data = move_._rv_data.data;
            move_._rv_data.data = nullptr;
            return *this;
        }

        game_value & game_value::operator=(const float val_)
        {
            if (_rv_data.data)
                _free();
            _rv_data.data = new game_data_number(val_);
            return *this;
        }

        game_value & game_value::operator=(bool val_)
        {
            if (_rv_data.data)
                _free();
            _rv_data.data = new game_data_bool(val_);
            return *this;
        }

        game_value & game_value::operator=(std::string val_)
        {
            if (_rv_data.data)
                _free();
            _rv_data.data = new game_data_string(val_);
            return *this;
        }

        game_value & game_value::operator=(const char * val_)
        {
            if (_rv_data.data)
                _free();
            _rv_data.data = new game_data_string(val_);
            return *this;
        }

        game_value & game_value::operator=(std::initializer_list<game_value> list_)
        {
            if (_rv_data.data)
                _free();
            _rv_data.data = new game_data_array(list_);
            return *this;
        }

        game_value & game_value::operator=(vector3 vec_)
        {
            if (_rv_data.data)
                _free();
            _rv_data.data = new game_data_array({ vec_.x, vec_.y, vec_.z });
            return *this;
        }

        game_value & game_value::operator=(vector2 vec_)
        {
            if (_rv_data.data)
                _free();
            _rv_data.data = new game_data_array({ vec_.x, vec_.y });
            return *this;
        }

        game_value & game_value::operator=(internal_object internal_)
        {
            if (_rv_data.data)
                _free();
            _rv_data.data = ((game_value)internal_)._rv_data.data;
            _rv_data.__vptr = ((game_value)internal_)._rv_data.__vptr;
            return *this;
        }

        game_value & game_value::operator=(rv_game_value internal_)
        {
            if (_rv_data.data)
                _free();
            _rv_data.data = internal_.data;
            _rv_data.__vptr = internal_.__vptr;
            return *this;
        }

        game_value::operator float()
        {
            if (_rv_data.data && _rv_data.data->type == game_data_number::type_def)
                return ((game_data_number *)_rv_data.data)->number;
            return 0.0f;
        }

        game_value::operator bool()
        {
            if (_rv_data.data && _rv_data.data->type == game_data_bool::type_def)
                return ((game_data_bool *)_rv_data.data)->val;
            return false;
        }

        game_value::operator rv_game_value *()
        {
            return &_rv_data;
        }

        game_value::operator float() const
        {
            if (_rv_data.data && _rv_data.data->type == game_data_number::type_def)
                return ((game_data_number *)_rv_data.data)->number;
            return 0.0f;
        }

        game_value::operator bool() const
        {
            if (_rv_data.data && _rv_data.data->type == game_data_bool::type_def)
                return ((game_data_bool *)_rv_data.data)->val;
            return false;
        }

        game_value::operator std::string() const
        {
            if (_rv_data.data && _rv_data.data->type == game_data_string::type_def)
                return std::string(&((game_data_string *)_rv_data.data)->raw_string->char_string);
            return std::string();
        }

        game_value::operator std::string()
        {
            if (_rv_data.data && _rv_data.data->type == game_data_string::type_def)
                return std::string(&((game_data_string *)_rv_data.data)->raw_string->char_string);
            return std::string();
        }

        game_value & game_value::operator [](int i_) {
            assert(_rv_data.data && _rv_data.data->type == game_data_array::type_def && i_ < ((game_data_array *)_rv_data.data)->length);
            return ((game_data_array *)_rv_data.data)->data[i_];
        }

        game_value game_value::operator [](int i_) const {
            assert(_rv_data.data && _rv_data.data->type == game_data_array::type_def && i_ < ((game_data_array *)_rv_data.data)->length);
            return ((game_data_array *)_rv_data.data)->data[i_];
        }

        uintptr_t game_value::type() {
            if (_rv_data.data)
                return _rv_data.data->type;
            return 0x0;
        }

        bool game_value::client_owned() {
            if (_rv_data.data && _rv_data.data->ref_count_internal == 0x0000dede)
                return true;
            return false;
        }



        rv_string * allocate_string(size_t size_) {
            return client::host::functions.allocate_string(size_);
        }

        void free_string(rv_string * str_) {
            client::host::functions.free_string(str_);
        }

        const void rv_game_value::deallocate()
        {
            data = nullptr;
        }

}
}


