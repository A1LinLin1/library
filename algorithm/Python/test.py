import jinja2
{% macro input(name,age=18) %}
    <input type="text" name="{{ name }}" value="{{ age }}">
{% endmacro %}