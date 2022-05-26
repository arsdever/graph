#pragma once

#include <concepts>
#include <memory>

namespace graph
{
#pragma region pointers
    template <typename T>
    using shared = std::shared_ptr<T>;

    template <typename T>
    using weak = std::weak_ptr<T>;

    template <typename T>
    using unique = std::unique_ptr<T>;
#pragma endregion

    // https://stackoverflow.com/a/60491447/10185183
    template <class C>
    concept is_container = requires(C a, const C b)
    {
        requires std::regular<C>;
        requires std::swappable<C>;
        requires std::destructible<typename C::value_type>;
        requires std::same_as<typename C::reference, typename C::value_type&>;
        requires std::same_as<typename C::const_reference,
                              const typename C::value_type&>;
        requires std::forward_iterator<typename C::iterator>;
        requires std::forward_iterator<typename C::const_iterator>;
        requires std::signed_integral<typename C::difference_type>;
        requires std::same_as<typename C::difference_type,
                              typename std::iterator_traits<
                                  typename C::iterator>::difference_type>;
        requires std::same_as<typename C::difference_type,
                              typename std::iterator_traits<
                                  typename C::const_iterator>::difference_type>;
        {
            a.begin()
            } -> std::convertible_to<typename C::iterator>;
        {
            a.end()
            } -> std::convertible_to<typename C::iterator>;
        {
            b.begin()
            } -> std::convertible_to<typename C::const_iterator>;
        {
            b.end()
            } -> std::convertible_to<typename C::const_iterator>;
        {
            a.cbegin()
            } -> std::convertible_to<typename C::const_iterator>;
        {
            a.cend()
            } -> std::convertible_to<typename C::const_iterator>;
        {
            a.size()
            } -> std::convertible_to<typename C::size_type>;
        {
            a.max_size()
            } -> std::convertible_to<typename C::size_type>;
        {
            a.empty()
            } -> std::convertible_to<bool>;
    };

    template <typename T>
    concept has_id = requires(T t)
    {
        typename T::id_t;
        {
            t.id()
            } -> std::convertible_to<typename T::id_t>;
    };

    template <typename T>
    concept defines_ptr_types = requires(T t)
    {
        typename T::ptr_t;
        typename T::wptr_t;
        typename T::uptr_t;
    };

    template <typename T>
    concept is_vertex = has_id<T> && defines_ptr_types<T>;

    template <typename T>
    concept is_edge = has_id<T> && defines_ptr_types<T> && requires(T t)
    {
        typename T::source_t;
        typename T::target_t;
        {
            t.source()
            } -> std::convertible_to<typename T::source_t>;
        {
            t.target()
            } -> std::convertible_to<typename T::target_t>;
    };
} // namespace graph