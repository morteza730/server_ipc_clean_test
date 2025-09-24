#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

// #define NDEBUG
#include <cassert>

#include "presenter/viewmodels/iViewmodel.hpp"

constexpr int NOT_FOUND = -1;

//=============================== viewmodel wrapper ==================================
template <typename TViewmodel>
struct Viewmodel: public IViewmodel
{
    static std::size_t getId() {
        static auto id = nextId++;
        return id;
    }
};

//================================ Pool of viewmodels =================================
class IPool {
public:
    virtual ~IPool() = default;
};

template <typename TViewmodel>
class Pool: public IPool {
private:
    std::vector<std::shared_ptr<IViewmodel>> data;

public:
    static_assert(std::is_base_of<IViewmodel,TViewmodel>::value,
                  "Template argument must be an IViewmodel."
                  );

    Pool() = default;

    virtual ~Pool() = default;

    bool isEmpty() const {return data.empty();}

    std::size_t size() const {return data.size();}

    void resize(int n) {data.resize(n); }

    void clear() {data.clear();}

    void add(std::shared_ptr<TViewmodel> object) {data.push_back(object);}

    void set(std::size_t index, std::shared_ptr<TViewmodel> object)
    {
        if (index >= data.size()) throw std::out_of_range("Index out of bounds");
        data[index] = object;
    }

    bool has(const std::shared_ptr<TViewmodel> &object) const {return has(object->label);}

    std::size_t has(const std::string &label) const
    {
        for(auto it = data.cbegin(); it != data.cend(); ++it)
        {
            if ((*it)->label == label)
                return it - data.cbegin();
        }
        return NOT_FOUND;
    }

    std::shared_ptr<TViewmodel> get(std::size_t index)
    {
        if (index >= data.size()) throw std::out_of_range("Index out of bounds");
        return std::static_pointer_cast<TViewmodel>(data[index]);
    }

    std::shared_ptr<TViewmodel> operator [](std::size_t index)
    {
        return get(index);
    }
};

//================================ registry of viewmodels =============================
class ViewmodelInterface;
class ViewmodelRegistry
{
    friend class ViewmodelInterface;
public:
    ~ViewmodelRegistry();

    ViewmodelRegistry(const ViewmodelRegistry&) = delete;
    ViewmodelRegistry& operator=(const ViewmodelRegistry&) = delete;

    static ViewmodelRegistry &get(){
        static ViewmodelRegistry instance;
        return instance;
    }

    template <typename TViewmodel>
    std::shared_ptr<TViewmodel> loadViewmodel(const std::string& label);


private:
    ViewmodelRegistry();
    std::vector<std::shared_ptr<IPool>> viewmodelPools;
    // Interface to make viewmodels accessible to view.
    std::unique_ptr<ViewmodelInterface> interface;

    template <typename TViewmodel, typename... Args>
    std::shared_ptr<TViewmodel> createViewmodel(const std::string &label, Args&&... args);
};


template <typename TViewmodel>
std::shared_ptr<TViewmodel> ViewmodelRegistry::loadViewmodel(const std::string& label)
{
    const auto viewmodelId = Viewmodel<TViewmodel>::getId();
    std::shared_ptr<Pool<TViewmodel>> viewmodelPool = std::static_pointer_cast<Pool<TViewmodel>>(viewmodelPools.at(viewmodelId));

    assert(viewmodelPool->has(label) != NOT_FOUND && "Viewmodel does not exist!"); // only works in debug mode.

    std::size_t index = viewmodelPool->has(label);
    return viewmodelPool->get(index);
}

template <typename TViewmodel, typename... Args>
std::shared_ptr<TViewmodel> ViewmodelRegistry::createViewmodel(const std::string &label, Args&&... args)
{
    const auto viewmodelId = Viewmodel<TViewmodel>::getId();

    if (viewmodelId >= viewmodelPools.size())
        viewmodelPools.resize(viewmodelId + 1, nullptr);

    if(!viewmodelPools[viewmodelId]) {
        std::shared_ptr<Pool<TViewmodel>> newViewmodelPool = std::make_shared<Pool<TViewmodel>>();
        viewmodelPools[viewmodelId] = newViewmodelPool;
    }

    std::shared_ptr<Pool<TViewmodel>> viewmodelPool = std::static_pointer_cast<Pool<TViewmodel>>(viewmodelPools.at(viewmodelId));

    assert(viewmodelPool->has(label) == NOT_FOUND && "Viewmodel already exist!"); // only works in debug mode.

    std::shared_ptr<TViewmodel> newViewmodel = std::make_shared<TViewmodel>(std::forward<Args>(args)...);
    newViewmodel->label = label;
    viewmodelPool->add(newViewmodel);

    return newViewmodel;
}
