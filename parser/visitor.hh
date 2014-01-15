/*
 * descripten - ECMAScript to native compiler
 * Copyright (C) 2011-2013 Christian Kindahl
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

namespace parser {

class Node;

class BinaryExpression;
class UnaryExpression;
class AssignmentExpression;
class ConditionalExpression;
class PropertyExpression;
class CallExpression;
class CallNewExpression;
class RegularExpression;
class FunctionExpression;
class ThisLiteral;
class IdentifierLiteral;
class NullLiteral;
class BoolLiteral;
class NumberLiteral;
class StringLiteral;
class FunctionLiteral;
class ArrayLiteral;
class ObjectLiteral;
class NothingLiteral;
class EmptyStatement;
class ExpressionStatement;
class BlockStatement;
class IfStatement;
class DoWhileStatement;
class WhileStatement;
class ForInStatement;
class ForStatement;
class ContinueStatement;
class BreakStatement;
class ReturnStatement;
class WithStatement;
class SwitchStatement;
class ThrowStatement;
class TryStatement;
class DebuggerStatement;

/**
 * @brief AST vistor base class.
 */
class Visitor
{
public:
    virtual ~Visitor() {}

    void visit(Node *node);

    virtual void visit_binary_expr(BinaryExpression *expr) = 0;
    virtual void visit_unary_expr(UnaryExpression *expr) = 0;
    virtual void visit_assign_expr(AssignmentExpression *expr) = 0;
    virtual void visit_cond_expr(ConditionalExpression *expr) = 0;
    virtual void visit_prop_expr(PropertyExpression *expr) = 0;
    virtual void visit_call_expr(CallExpression *expr) = 0;
    virtual void visit_call_new_expr(CallNewExpression *expr) = 0;
    virtual void visit_regular_expr(RegularExpression *expr) = 0;
    virtual void visit_fun_expr(FunctionExpression *expr) = 0;

    virtual void visit_this_lit(ThisLiteral *lit) = 0;
    virtual void visit_ident_lit(IdentifierLiteral *lit) = 0;
    virtual void visit_null_lit(NullLiteral *lit) = 0;
    virtual void visit_bool_lit(BoolLiteral *lit) = 0;
    virtual void visit_num_lit(NumberLiteral *lit) = 0;
    virtual void visit_str_lit(StringLiteral *lit) = 0;
    virtual void visit_fun_lit(FunctionLiteral *lit) = 0;
    virtual void visit_var_lit(VariableLiteral *lit) = 0;
    virtual void visit_array_lit(ArrayLiteral *lit) = 0;
    virtual void visit_obj_lit(ObjectLiteral *lit) = 0;
    virtual void visit_nothing_lit(NothingLiteral *lit) = 0;

    virtual void visit_empty_stmt(EmptyStatement *stmt) = 0;
    virtual void visit_expr_stmt(ExpressionStatement *stmt) = 0;
    virtual void visit_block_stmt(BlockStatement *stmt) = 0;
    virtual void visit_if_stmt(IfStatement *stmt) = 0;
    virtual void visit_do_while_stmt(DoWhileStatement *stmt) = 0;
    virtual void visit_while_stmt(WhileStatement *stmt) = 0;
    virtual void visit_for_in_stmt(ForInStatement *stmt) = 0;
    virtual void visit_for_stmt(ForStatement *stmt) = 0;
    virtual void visit_cont_stmt(ContinueStatement *stmt) = 0;
    virtual void visit_break_stmt(BreakStatement *stmt) = 0;
    virtual void visit_ret_stmt(ReturnStatement *stmt) = 0;
    virtual void visit_with_stmt(WithStatement *stmt) = 0;
    virtual void visit_switch_stmt(SwitchStatement *stmt) = 0;
    virtual void visit_throw_stmt(ThrowStatement *stmt) = 0;
    virtual void visit_try_stmt(TryStatement *stmt) = 0;
    virtual void visit_dbg_stmt(DebuggerStatement *stmt) = 0;
};

/**
 * @brief AST visitor base class with support for return value.
 */
template <typename T>
class ValueVisitor : private Visitor
{
private:
    T value_;

protected:
    T parse(Node *node)
    {
        visit(node);
        return value_;
    }

    virtual ~ValueVisitor() {}

private:
    virtual void visit_binary_expr(BinaryExpression *expr) OVERRIDE
    {
        value_ = parse_binary_expr(expr);
    }

    virtual void visit_unary_expr(UnaryExpression *expr) OVERRIDE
    {
        value_ = parse_unary_expr(expr);
    }

    virtual void visit_assign_expr(AssignmentExpression *expr) OVERRIDE
    {
        value_ = parse_assign_expr(expr);
    }

    virtual void visit_cond_expr(ConditionalExpression *expr) OVERRIDE
    {
        value_ = parse_cond_expr(expr);
    }

    virtual void visit_prop_expr(PropertyExpression *expr) OVERRIDE
    {
        value_ = parse_prop_expr(expr);
    }

    virtual void visit_call_expr(CallExpression *expr) OVERRIDE
    {
        value_ = parse_call_expr(expr);
    }

    virtual void visit_call_new_expr(CallNewExpression *expr) OVERRIDE
    {
        value_ = parse_call_new_expr(expr);
    }

    virtual void visit_regular_expr(RegularExpression *expr) OVERRIDE
    {
        value_ = parse_regular_expr(expr);
    }

    virtual void visit_fun_expr(FunctionExpression *expr) OVERRIDE
    {
        value_ = parse_fun_expr(expr);
    }

    virtual void visit_this_lit(ThisLiteral *lit) OVERRIDE
    {
        value_ = parse_this_lit(lit);
    }

    virtual void visit_ident_lit(IdentifierLiteral *lit) OVERRIDE
    {
        value_ = parse_ident_lit(lit);
    }

    virtual void visit_null_lit(NullLiteral *lit) OVERRIDE
    {
        value_ = parse_null_lit(lit);
    }

    virtual void visit_bool_lit(BoolLiteral *lit) OVERRIDE
    {
        value_ = parse_bool_lit(lit);
    }

    virtual void visit_num_lit(NumberLiteral *lit) OVERRIDE
    {
        value_ = parse_num_lit(lit);
    }

    virtual void visit_str_lit(StringLiteral *lit) OVERRIDE
    {
        value_ = parse_str_lit(lit);
    }

    virtual void visit_fun_lit(FunctionLiteral *lit) OVERRIDE
    {
        value_ = parse_fun_lit(lit);
    }

    virtual void visit_var_lit(VariableLiteral *lit) OVERRIDE
    {
        value_ = parse_var_lit(lit);
    }

    virtual void visit_array_lit(ArrayLiteral *lit) OVERRIDE
    {
        value_ = parse_array_lit(lit);
    }

    virtual void visit_obj_lit(ObjectLiteral *lit) OVERRIDE
    {
        value_ = parse_obj_lit(lit);
    }

    virtual void visit_nothing_lit(NothingLiteral *lit) OVERRIDE
    {
        value_ = parse_nothing_lit(lit);
    }

    virtual void visit_empty_stmt(EmptyStatement *stmt) OVERRIDE
    {
        value_ = parse_empty_stmt(stmt);
    }

    virtual void visit_expr_stmt(ExpressionStatement *stmt) OVERRIDE
    {
        value_ = parse_expr_stmt(stmt);
    }

    virtual void visit_block_stmt(BlockStatement *stmt) OVERRIDE
    {
        value_ = parse_block_stmt(stmt);
    }

    virtual void visit_if_stmt(IfStatement *stmt) OVERRIDE
    {
        value_ = parse_if_stmt(stmt);
    }

    virtual void visit_do_while_stmt(DoWhileStatement *stmt) OVERRIDE
    {
        value_ = parse_do_while_stmt(stmt);
    }

    virtual void visit_while_stmt(WhileStatement *stmt) OVERRIDE
    {
        value_ = parse_while_stmt(stmt);
    }

    virtual void visit_for_in_stmt(ForInStatement *stmt) OVERRIDE
    {
        value_ = parse_for_in_stmt(stmt);
    }

    virtual void visit_for_stmt(ForStatement *stmt) OVERRIDE
    {
        value_ = parse_for_stmt(stmt);
    }

    virtual void visit_cont_stmt(ContinueStatement *stmt) OVERRIDE
    {
        value_ = parse_cont_stmt(stmt);
    }

    virtual void visit_break_stmt(BreakStatement *stmt) OVERRIDE
    {
        value_ = parse_break_stmt(stmt);
    }

    virtual void visit_ret_stmt(ReturnStatement *stmt) OVERRIDE
    {
        value_ = parse_ret_stmt(stmt);
    }

    virtual void visit_with_stmt(WithStatement *stmt) OVERRIDE
    {
        value_ = parse_with_stmt(stmt);
    }

    virtual void visit_switch_stmt(SwitchStatement *stmt) OVERRIDE
    {
        value_ = parse_switch_stmt(stmt);
    }

    virtual void visit_throw_stmt(ThrowStatement *stmt) OVERRIDE
    {
        value_ = parse_throw_stmt(stmt);
    }

    virtual void visit_try_stmt(TryStatement *stmt) OVERRIDE
    {
        value_ = parse_try_stmt(stmt);
    }

    virtual void visit_dbg_stmt(DebuggerStatement *stmt) OVERRIDE
    {
        value_ = parse_dbg_stmt(stmt);
    }

public:
    virtual T parse_binary_expr(BinaryExpression *expr) = 0;
    virtual T parse_unary_expr(UnaryExpression *expr) = 0;
    virtual T parse_assign_expr(AssignmentExpression *expr) = 0;
    virtual T parse_cond_expr(ConditionalExpression *expr) = 0;
    virtual T parse_prop_expr(PropertyExpression *expr) = 0;
    virtual T parse_call_expr(CallExpression *expr) = 0;
    virtual T parse_call_new_expr(CallNewExpression *expr) = 0;
    virtual T parse_regular_expr(RegularExpression *expr) = 0;
    virtual T parse_fun_expr(FunctionExpression *expr) = 0;

    virtual T parse_this_lit(ThisLiteral *lit) = 0;
    virtual T parse_ident_lit(IdentifierLiteral *lit) = 0;
    virtual T parse_null_lit(NullLiteral *lit) = 0;
    virtual T parse_bool_lit(BoolLiteral *lit) = 0;
    virtual T parse_num_lit(NumberLiteral *lit) = 0;
    virtual T parse_str_lit(StringLiteral *lit) = 0;
    virtual T parse_fun_lit(FunctionLiteral *lit) = 0;
    virtual T parse_var_lit(VariableLiteral *lit) = 0;
    virtual T parse_array_lit(ArrayLiteral *lit) = 0;
    virtual T parse_obj_lit(ObjectLiteral *lit) = 0;
    virtual T parse_nothing_lit(NothingLiteral *lit) = 0;

    virtual T parse_empty_stmt(EmptyStatement *stmt) = 0;
    virtual T parse_expr_stmt(ExpressionStatement *stmt) = 0;
    virtual T parse_block_stmt(BlockStatement *stmt) = 0;
    virtual T parse_if_stmt(IfStatement *stmt) = 0;
    virtual T parse_do_while_stmt(DoWhileStatement *stmt) = 0;
    virtual T parse_while_stmt(WhileStatement *stmt) = 0;
    virtual T parse_for_in_stmt(ForInStatement *stmt) = 0;
    virtual T parse_for_stmt(ForStatement *stmt) = 0;
    virtual T parse_cont_stmt(ContinueStatement *stmt) = 0;
    virtual T parse_break_stmt(BreakStatement *stmt) = 0;
    virtual T parse_ret_stmt(ReturnStatement *stmt) = 0;
    virtual T parse_with_stmt(WithStatement *stmt) = 0;
    virtual T parse_switch_stmt(SwitchStatement *stmt) = 0;
    virtual T parse_throw_stmt(ThrowStatement *stmt) = 0;
    virtual T parse_try_stmt(TryStatement *stmt) = 0;
    virtual T parse_dbg_stmt(DebuggerStatement *stmt) = 0;
};

/**
 * @brief AST visitor base class with support for return value and a single parameter.
 */
template <typename T, typename P>
class ValueVisitor1 : private Visitor
{
private:
    T value_;
    P param_;

protected:
    T parse(Node *node, P param)
    {
        param_ = param;
        visit(node);
        return value_;
    }

    virtual ~ValueVisitor1() {}

private:
    virtual void visit_binary_expr(BinaryExpression *expr) OVERRIDE
    {
        value_ = parse_binary_expr(expr, param_);
    }

    virtual void visit_unary_expr(UnaryExpression *expr) OVERRIDE
    {
        value_ = parse_unary_expr(expr, param_);
    }

    virtual void visit_assign_expr(AssignmentExpression *expr) OVERRIDE
    {
        value_ = parse_assign_expr(expr, param_);
    }

    virtual void visit_cond_expr(ConditionalExpression *expr) OVERRIDE
    {
        value_ = parse_cond_expr(expr, param_);
    }

    virtual void visit_prop_expr(PropertyExpression *expr) OVERRIDE
    {
        value_ = parse_prop_expr(expr, param_);
    }

    virtual void visit_call_expr(CallExpression *expr) OVERRIDE
    {
        value_ = parse_call_expr(expr, param_);
    }

    virtual void visit_call_new_expr(CallNewExpression *expr) OVERRIDE
    {
        value_ = parse_call_new_expr(expr, param_);
    }

    virtual void visit_regular_expr(RegularExpression *expr) OVERRIDE
    {
        value_ = parse_regular_expr(expr, param_);
    }

    virtual void visit_fun_expr(FunctionExpression *expr) OVERRIDE
    {
        value_ = parse_fun_expr(expr, param_);
    }

    virtual void visit_this_lit(ThisLiteral *lit) OVERRIDE
    {
        value_ = parse_this_lit(lit, param_);
    }

    virtual void visit_ident_lit(IdentifierLiteral *lit) OVERRIDE
    {
        value_ = parse_ident_lit(lit, param_);
    }

    virtual void visit_null_lit(NullLiteral *lit) OVERRIDE
    {
        value_ = parse_null_lit(lit, param_);
    }

    virtual void visit_bool_lit(BoolLiteral *lit) OVERRIDE
    {
        value_ = parse_bool_lit(lit, param_);
    }

    virtual void visit_num_lit(NumberLiteral *lit) OVERRIDE
    {
        value_ = parse_num_lit(lit, param_);
    }

    virtual void visit_str_lit(StringLiteral *lit) OVERRIDE
    {
        value_ = parse_str_lit(lit, param_);
    }

    virtual void visit_fun_lit(FunctionLiteral *lit) OVERRIDE
    {
        value_ = parse_fun_lit(lit, param_);
    }

    virtual void visit_var_lit(VariableLiteral *lit) OVERRIDE
    {
        value_ = parse_var_lit(lit, param_);
    }

    virtual void visit_array_lit(ArrayLiteral *lit) OVERRIDE
    {
        value_ = parse_array_lit(lit, param_);
    }

    virtual void visit_obj_lit(ObjectLiteral *lit) OVERRIDE
    {
        value_ = parse_obj_lit(lit, param_);
    }

    virtual void visit_nothing_lit(NothingLiteral *lit) OVERRIDE
    {
        value_ = parse_nothing_lit(lit, param_);
    }

    virtual void visit_empty_stmt(EmptyStatement *stmt) OVERRIDE
    {
        value_ = parse_empty_stmt(stmt, param_);
    }

    virtual void visit_expr_stmt(ExpressionStatement *stmt) OVERRIDE
    {
        value_ = parse_expr_stmt(stmt, param_);
    }

    virtual void visit_block_stmt(BlockStatement *stmt) OVERRIDE
    {
        value_ = parse_block_stmt(stmt, param_);
    }

    virtual void visit_if_stmt(IfStatement *stmt) OVERRIDE
    {
        value_ = parse_if_stmt(stmt, param_);
    }

    virtual void visit_do_while_stmt(DoWhileStatement *stmt) OVERRIDE
    {
        value_ = parse_do_while_stmt(stmt, param_);
    }

    virtual void visit_while_stmt(WhileStatement *stmt) OVERRIDE
    {
        value_ = parse_while_stmt(stmt, param_);
    }

    virtual void visit_for_in_stmt(ForInStatement *stmt) OVERRIDE
    {
        value_ = parse_for_in_stmt(stmt, param_);
    }

    virtual void visit_for_stmt(ForStatement *stmt) OVERRIDE
    {
        value_ = parse_for_stmt(stmt, param_);
    }

    virtual void visit_cont_stmt(ContinueStatement *stmt) OVERRIDE
    {
        value_ = parse_cont_stmt(stmt, param_);
    }

    virtual void visit_break_stmt(BreakStatement *stmt) OVERRIDE
    {
        value_ = parse_break_stmt(stmt, param_);
    }

    virtual void visit_ret_stmt(ReturnStatement *stmt) OVERRIDE
    {
        value_ = parse_ret_stmt(stmt, param_);
    }

    virtual void visit_with_stmt(WithStatement *stmt) OVERRIDE
    {
        value_ = parse_with_stmt(stmt, param_);
    }

    virtual void visit_switch_stmt(SwitchStatement *stmt) OVERRIDE
    {
        value_ = parse_switch_stmt(stmt, param_);
    }

    virtual void visit_throw_stmt(ThrowStatement *stmt) OVERRIDE
    {
        value_ = parse_throw_stmt(stmt, param_);
    }

    virtual void visit_try_stmt(TryStatement *stmt) OVERRIDE
    {
        value_ = parse_try_stmt(stmt, param_);
    }

    virtual void visit_dbg_stmt(DebuggerStatement *stmt) OVERRIDE
    {
        value_ = parse_dbg_stmt(stmt, param_);
    }

public:
    virtual T parse_binary_expr(BinaryExpression *expr, P param) = 0;
    virtual T parse_unary_expr(UnaryExpression *expr, P param) = 0;
    virtual T parse_assign_expr(AssignmentExpression *expr, P param) = 0;
    virtual T parse_cond_expr(ConditionalExpression *expr, P param) = 0;
    virtual T parse_prop_expr(PropertyExpression *expr, P param) = 0;
    virtual T parse_call_expr(CallExpression *expr, P param) = 0;
    virtual T parse_call_new_expr(CallNewExpression *expr, P param) = 0;
    virtual T parse_regular_expr(RegularExpression *expr, P param) = 0;
    virtual T parse_fun_expr(FunctionExpression *expr, P param) = 0;

    virtual T parse_this_lit(ThisLiteral *lit, P param) = 0;
    virtual T parse_ident_lit(IdentifierLiteral *lit, P param) = 0;
    virtual T parse_null_lit(NullLiteral *lit, P param) = 0;
    virtual T parse_bool_lit(BoolLiteral *lit, P param) = 0;
    virtual T parse_num_lit(NumberLiteral *lit, P param) = 0;
    virtual T parse_str_lit(StringLiteral *lit, P param) = 0;
    virtual T parse_fun_lit(FunctionLiteral *lit, P param) = 0;
    virtual T parse_var_lit(VariableLiteral *lit, P param) = 0;
    virtual T parse_array_lit(ArrayLiteral *lit, P param) = 0;
    virtual T parse_obj_lit(ObjectLiteral *lit, P param) = 0;
    virtual T parse_nothing_lit(NothingLiteral *lit, P param) = 0;

    virtual T parse_empty_stmt(EmptyStatement *stmt, P param) = 0;
    virtual T parse_expr_stmt(ExpressionStatement *stmt, P param) = 0;
    virtual T parse_block_stmt(BlockStatement *stmt, P param) = 0;
    virtual T parse_if_stmt(IfStatement *stmt, P param) = 0;
    virtual T parse_do_while_stmt(DoWhileStatement *stmt, P param) = 0;
    virtual T parse_while_stmt(WhileStatement *stmt, P param) = 0;
    virtual T parse_for_in_stmt(ForInStatement *stmt, P param) = 0;
    virtual T parse_for_stmt(ForStatement *stmt, P param) = 0;
    virtual T parse_cont_stmt(ContinueStatement *stmt, P param) = 0;
    virtual T parse_break_stmt(BreakStatement *stmt, P param) = 0;
    virtual T parse_ret_stmt(ReturnStatement *stmt, P param) = 0;
    virtual T parse_with_stmt(WithStatement *stmt, P param) = 0;
    virtual T parse_switch_stmt(SwitchStatement *stmt, P param) = 0;
    virtual T parse_throw_stmt(ThrowStatement *stmt, P param) = 0;
    virtual T parse_try_stmt(TryStatement *stmt, P param) = 0;
    virtual T parse_dbg_stmt(DebuggerStatement *stmt, P param) = 0;
};

}
