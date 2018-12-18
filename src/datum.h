//
// Created by sushant on 12/16/18.
//

#ifndef STBOOST_DATA_H
#define STBOOST_DATA_H
namespace stboost {
    template<typename X>
    class datum {
    public:
        datum();

        datum(X &value);

        bool is_null();

        void set_null();

        //Assignment operator
        void operator=(const datum<X> &input);

        void operator=(const X &input);


        //Comparison operators
        bool operator==(const datum<X> &input);

        bool operator!=(const datum<X> &input);

        bool operator>(const datum<X> &input);

        bool operator>=(const datum<X> &input);

        bool operator<(const datum<X> &input);

        bool operator<=(const datum<X> &input);

    protected:
        bool null_indicator;
        X value;

    };

    template<typename X>
    datum<X>::datum() {
        this->null_indicator = true;
    }

    template<typename X>
    datum<X>::datum(X &value) {
        this->null_indicator = false;
        this->value = value;

    }

    template<typename X>
    bool datum<X>::is_null() {
        return this->null_indicator;
    }

    template<typename X>
    void datum<X>::operator=(const datum<X> &input) {
        this->null_indicator = input.null_indicator;
        this->value = input.value;

    }

    template<typename X>
    void datum<X>::operator=(const X &input) {
        this->null_indicator = false;
        this->value = input;
    }

    template<typename X>
    bool datum<X>::operator==(const datum<X> &input) {
        if (this->null_indicator == input.null_indicator) {
            return true;
        } else if (this->value == input.value) {
            return true;
        }
        return false;
    }

    template<typename X>
    bool datum<X>::operator!=(const datum<X> &input) {
        if (this->null_indicator != input.null_indicator) {
            return true;
        } else if (this->value != input.value) {
            return true;
        }
        return false;
    }

    template<typename X>
    bool datum<X>::operator>(const datum<X> &input) {
        if (this->null_indicator || input.null_indicator) {
            return false;
        } else if (this->value > input.value) {
            return true;
        }
        return false;
    }

    template<typename X>
    bool datum<X>::operator>=(const datum<X> &input) {
        if (this->null_indicator || input.null_indicator) {
            return false;
        } else if (this->value >= input.value) {
            return true;
        }
        return false;
    }

    template<typename X>
    bool datum<X>::operator<(const datum<X> &input) {
        if (this->null_indicator || input.null_indicator) {
            return false;
        } else if (this->value < input.value) {
            return true;
        }
        return false;
    }

    template<typename X>
    bool datum<X>::operator<=(const datum<X> &input) {
        if (this->null_indicator || input.null_indicator) {
            return false;
        } else if (this->value <= input.value) {
            return true;
        }
        return false;
    }

    template<typename X>
    void datum<X>::set_null() {
        this->null_indicator = true;
    }
};

#endif //STBOOST_DATA_H
