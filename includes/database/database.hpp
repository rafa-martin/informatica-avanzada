#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

namespace IA_Clinic {

class Database
{
    struct DataVectorBase_t {};

    template <typename DATA_t>
    struct DataVector_t : DataVectorBase_t {
        std::vector<DATA_t> data;

        static std::size_t getDataTypeID() {
            static std::size_t type{nextTypeID++};
            return type;
        }

    private:
        inline static std::size_t nextTypeID {0};
    };

    std::unordered_map<std::size_t, std::unique_ptr<DataVectorBase_t>> all_data_;

public:
    template <typename DATA_t>
    std::vector<DATA_t>& createDataVector() {
        auto typeID = DataVector_t<DATA_t>::getDataTypeID();
        auto v = std::make_unique<DataVector_t<DATA_t>>();
        //v->data.reserve(100);
        auto* vecptr = v.get();
        all_data_[typeID] = std::move(v);

        return vecptr->data;
    }

    template <typename DATA_t>
    std::vector<DATA_t>& getDataVector() {
        std::vector<DATA_t>* datavec {nullptr};
        auto typeID = DataVector_t<DATA_t>::getDataTypeID();
        auto it = all_data_.find(typeID);

        if (it != all_data_.end()) {
            auto* v = static_cast<DataVector_t<DATA_t>*>(it->second.get());
            datavec = &(v->data);
        } else {
            // Create if not exist before
            datavec = &createDataVector<DATA_t>();
        }

        return *datavec;
    }

    template <typename DATA_t>
    const std::vector<DATA_t>& getDataVector() const {
        std::vector<DATA_t>* datavec {nullptr};
        auto typeID = DataVector_t<DATA_t>::getDataTypeID();
        auto it = all_data_.find(typeID);

        if (it != all_data_.end()) {
            auto* v = static_cast<DataVector_t<DATA_t>*>(it->second.get());
            datavec = &(v->data);
        } else {
            // Cannot create becouse const access. Then throw exception.
            throw "Datatype was not inserted before and used in const!";
        }

        return *datavec;
    }

    template <typename DATA_t>
    DATA_t& createData() {
        auto& vec = getDataVector<DATA_t>();
        auto& data = vec.emplace_back();
        return data;
    }
};

} // namespace IA_Clinic
