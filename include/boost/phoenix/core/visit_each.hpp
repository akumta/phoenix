/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_VISIT_EACH_HPP
#define PHOENIX_CORE_VISIT_EACH_HPP

#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/visit_each.hpp>

namespace boost { namespace phoenix
{
    namespace detail
    {
        template <typename Visitor>
        struct visit_each_impl
        {
            Visitor& visitor;
            visit_each_impl(Visitor& visitor ) : visitor(visitor) {}

            template <typename T>
            void operator()(T const& t) const
            {
                visit_each(visitor, t);
            }
        };
    }

    template <typename Visitor, typename Expr>
    void visit_each(Visitor& visitor, actor<Expr> const& a, long)
    {
        fusion::for_each(a, detail::visit_each_impl<Visitor>(visitor));
    }
}}

#endif