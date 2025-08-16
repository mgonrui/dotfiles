; extends
(reference_declarator "&" @operator (#set! "priority" 1000))


;; ~/.config/nvim/queries/cpp/highlights.scm

;; Match copy constructor-style declarations and force as variables
((declaration
  type: (type_identifier)
  declarator: (function_declarator
    declarator: (identifier) @variable.declaration
    parameters: (parameter_list
      (parameter_declaration
        type: (type_identifier))))
) @_copy_ctor
(#set! "priority" 200)) ; Extreme priority to override function parsing
